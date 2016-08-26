#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define all(v) (v.begin(),v.end())
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        double h,p,g;
        cin>>h>>p>>g;
        cout.precision(2);
        cout<<fixed<<sqrt(2*g/h)<<endl;
    }
}
