#include <iostream>
#include <algorithm>
using namespace std;

const int NMAX = 86028125;
const int size= 7e6;
int start = size;
const int PRIME_INDEX_MAX = 5000005;

bool isprime[size];

int primes[PRIME_INDEX_MAX];    //vector ki jagah array.
int num_primes=0;

int main()
{
	fill (isprime, isprime + size, true);
	isprime[1] = false;
	for(int i=2; i<size; i++)
	{	if(isprime[i])
		{	for(int j=2*i; j<size; j+=i)
			{	isprime[j] = false;
			}
			primes[num_primes] = (i);
			num_primes++;
		}
	}
	
	//now, primes vector contains all primes upto 10^6.
	while((start < NMAX) && (num_primes < PRIME_INDEX_MAX))
	{	fill (isprime, isprime+ size, true);
		int upto = min(size, NMAX-start);
		for(int index=0; index<num_primes; index++)
		{   int i = primes[index];	
		    for(int j=(start/i)*i; j<upto + start; j+=i)
			{	if(j<start)
					continue;
				isprime[j-start]=false;
			}
		}
		for(int j=0; j<upto; j++)
		{	if(isprime[j])
			{	primes[num_primes] = j+start;
			    num_primes++;
		    }
		    if(num_primes >= PRIME_INDEX_MAX)
		        break;
		}
		start+= size;
	}
	
	// preprocesing complete.
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int Q;
	cin>>Q;
	while(Q--)
	{	int index;
		cin >> index;
		cout << primes[index-1]<<'\n';
	}
}
