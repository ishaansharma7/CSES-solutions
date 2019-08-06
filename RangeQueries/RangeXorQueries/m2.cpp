#include <bits/stdc++.h>

#define l(x) x << 1
#define r(x) (x << 1) | 1

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q, a, b;
    cin >> n >> q;
    vector<ll> sum(2 * n);

    for(int i = n; i < 2 * n; i++)
        cin >> sum[i];
    for(int i = n - 1; i > 0; i--)
        sum[i] = sum[l(i)] ^ sum[r(i)];
 
    while(q--){
        cin >> a >> b;
        a += n - 1;
        b += n;
        ll ans = 0;
        while(a < b){
            if(a & 1) ans ^= sum[a++];
            if(b & 1) ans ^= sum[--b];
            a >>= 1, b >>= 1;
        }
        cout << ans << "\n";
    }
 
    
}