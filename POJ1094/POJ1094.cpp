#include <iostream>
#include <algorithm>
using namespace std;
struct letter {
    char l;
    int f;
};
bool cmp (letter &a, letter &b) {
    return a.f<b.f;
}
bool MAP[27][27];
int main () {
    int n,m;
    while(cin >> n >>m && m + n !=0){
    for (int i = 1; i <= n;i++) 
        for (int j = 1; j<=n ;j++)
            MAP[i][j] = false;
    int count = 0;
    bool flag = 1;
    for (int i = 1; i <= m;i++) {
        char t[4];
        cin >> t;
        int x = t[0] - 'A' + 1;
        int y = t[2] - 'A' + 1;
        if (MAP[x][y]&&flag) {
            cout << "Inconsistency found after "<< i << " relations.\n";
            flag = 0;
        }
        if (MAP[y][x])
            continue;
        MAP[y][x] = true;
        count++;
        for (int i = 1; i<=n ;i++) {
            if (MAP[x][i]&&!MAP[y][i]) {
                MAP[y][i] = true;
                count++;
            }
            if (MAP[i][y]&&!MAP[i][x] ){
                MAP[i][x] = true;
                count++;
            }
        }
        if (count == (n*(n-1))/2&&flag) {
            flag = 0;
            letter ans[27];
            for (int i = 0; i<n;i++) {
                int ctn = 0;
                for (int j = 1; j <= n;j++) {
                    if (MAP[i+1][j])
                        ctn++;
                }
                ans[i].l = i+'A';
                ans[i].f = ctn;
            }
            sort(ans,ans+n,cmp);
            cout <<"Sorted sequence determined after " << i << " relations: ";
            for (int i = 0; i<n ;i++)
                cout << ans[i].l;
            cout << ".\n";
        }
    }
    if (flag)
        cout << "Sorted sequence cannot be determined.\n";
    }
    return 0;
}
