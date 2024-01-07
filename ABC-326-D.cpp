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
int n;
string r, c;
char grid[30][30];
int pos[3][5];

void ijprint()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}

bool check()
{
    for(int i=0; i<n; i++)
    {
        int tmp=0;
        while(grid[i][tmp] == '.')
        {
            tmp++;
        }
        if(grid[i][tmp] != r[i])
        {
            return 0;
        }
    }

    for(int i=0; i<n; i++)
    {
        int tmp=0;
        while(grid[tmp][i] == '.')
        {
            tmp++;
        }
        if(grid[tmp][i] != c[i])
        {
            return 0;
        }
    }

    return 1;
}

bool func(int level, int now)
{
    if(now==3)
    {
        if(check())
        {
            return 1;
        }
        return 0;
    }
    if(level==n)
    {
        return func(0, now+1);
    }

    for(int i=0; i<n; i++)
    {
        if(grid[level][i] != '.' || pos[now][i])
        {
            continue;
        }
        grid[level][i]='A'+now;
        pos[now][i]=1;
        if(func(level+1, now))
        {
            return 1;
        }
        grid[level][i]='.';
        pos[now][i]=0;
    }

    return 0;
}


void solve()
{
    cin>>n>>r>>c;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            grid[i][j]='.';
        }
    }

    if(func(0, 0))
    {
        cout<<"Yes"<<endl;
        ijprint();
    }
    else
    {
        cout<<"No"<<endl;
    }


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
