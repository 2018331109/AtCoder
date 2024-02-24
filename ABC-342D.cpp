#include<bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define neg cout << -1 << endl;
#define pb push_back
#define ss second
#define ff first
const int INF=1e18;
const int N=1e6+6;
const int md=998244353;

vector<int>primes(N, 1), p;

void seive()
{
    primes[0]=0, primes[1]=0;
    for(int i=2; i<N; i++)
    {
        if(primes[i])
        {
            for(int j=i*2; j<N; j+=i)
            {
                primes[j]=0;
            }
        }
    }
    for(int i=2;i<N;i++)
    {
        if(primes[i])
        {
            p.pb(i);
        }
    }
}

void solve()
{
    int n;
    cin>>n;
    vector<int>v(n);
    int cnt=0, ans=0;
    map<int, int>mp;

    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        if(x==0)
        {
            cnt++;
            continue;
        }
        for(auto it:p)
        {
            if(it*it>x)
            {
                break;
            }
            while(x%(it*it)==0)
            {
                x/=(it*it);
            }

        }
        ans+=mp[x]++;
    }

    ans+=cnt*(n-cnt);
    ans+=(cnt*(cnt-1))/2;

    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    //cin >> test;
    seive();

    for (int tc = 1; tc <= test; tc++)
    {
        solve();
    }

    return 0;
}
