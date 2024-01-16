#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define neg cout<<-1<<endl;
#define ff first
#define ss second

const int mod = 1e9 + 7;
const int md = 998244353;
const int INF = 1e18;

vector<int>v;
int n;
int check(int k)
{
    if(k==1)
    {
        return 1;
    }
    int cur=1, add=1;
    for(int i=0; i<n; i++)
    {
        if(v[i]>=cur)
        {
            cur+=add;
            if(cur==0 && add==-1)
            {
                return 1;
            }
            if(cur==k+1)
            {
                cur=k-1;
                add=-1;
            }
        }
        else
        {
            cur=v[i]+1;
            add=1;
        }
    }

    return 0;
}

void solve()
{
    cin>>n;
    v.clear();
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        v.pb(x);
    }
    int l=0, r=(n+1)/2, ans=0;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(check(m))
        {
            ans=m;
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }

    cout<<ans<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    //cin >> test;

    for (int tc = 1; tc <= test; tc++)
    {
        solve();
    }

    return 0;
}
