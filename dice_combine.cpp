#pragma GCC optimize ("Ofast","unroll-loops")
#include <bits/stdc++.h>
#define PB push_back
#define eb emplace_back
#define MK make_pair
#define F first
#define S second
#define setpre(a) cout.precision(a),cout<<fixed;
#define endl "\n"
#define ALL(a) a.begin(),a.end()
#define MEM(a,b) memset(a,b,sizeof a)
#define TIE ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
 
 
int dp[1000010];
int coin[6]={1,2,3,4,5,6};
int n;
int M=(int)1e9+7;
 
void count_dp(){
 
    dp[0]=1;
    for(int i=1;i<=6;i++){
        for(int j=i;j<=n;j++){
            dp[j]+=dp[j-i];
        }
    }
    cout<<"-------combine-------"<<endl;
    for(int i=0;i<=n;i++)cout<<dp[i]<<" ";
    cout<<endl;
    //reset dp
    MEM(dp,0);
    dp[0]=1;
    
    for(int i=1;i<=n;i++){
        dp[i]=0;
        for(int j=1;j<=i&&j<=6;j++){
            dp[i]+=(dp[i-j]%M);
            dp[i]%=M;
        }
    }

    cout<<"-------arrange-------"<<endl;
    for(int i=0;i<=n;i++)cout<<dp[i]<<" ";
    cout<<endl;
    
    cout<<dp[n]<<endl;
}
 
int main(){TIE
    cin>>n;
    MEM(dp,0);
    count_dp();
    return 0;
}