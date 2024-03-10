#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;

struct TreeNode {
    char num;
    TreeNode *left;
    TreeNode *right;

    TreeNode(char a = ' ') : num(a) {}
};

//while(scanf("%d",&n)!=EOF){}
//输入输出均使用c风格然后代码处用C++风格
//char str[100];//使用scanf来输入这个
//scanf("%s",str);//只读取了一个单词不会读取一整行
//fgets(str,sizeof(str),stdin);//读取一整行包括换行符
//while(fgets(str,sizeof(str),stdin)!=nullptr){//不确定行数的多行读取
//      string s = str;//转换为string类型
//      s.pop_back();//弹出最后的换行符
//
// }
//string str1 =str;
//str1.erase(str1.size()-1);
//str1.find("was")==string::npos;//来判断是否找到
//printf("%s\n",str1.c_str());//用c_str()来转换成c风格
//stod(str);//将string转换成double
int sum_is_532() {
    int a, b, c;
    for (a = 0; a <= 9; a++) {
        for (b = 0; b <= 9; b++) {
            for (c = 0; c <= 9; c++) {
                if (a * 100 + b * 10 + c + b * 100 + c * 10 + c == 532) {
                    cout << "a" << a << " b" << b << " c" << c << endl;
                }
            }
        }
    }
}

int is_reverseNum() {
    int a, b, c, d;
    for (a = 0; a <= 9; a++) {
        for (b = 0; b <= 9; b++) {
            for (c = 0; c <= 9; c++) {
                for (d = 0; d <= 9; d++) {
                    if ((a * 1000 + b * 100 + c * 10 + d) * 9 == d * 1000 + c * 100 + b * 10 + a) {
                        cout << a * 1000 + b * 100 + c * 10 + d << endl;
                    }
                }
            }
        }
    }
}

int reverseNum(int n) {
    int remain;
    int reverse = 0;
    while (n > 0) {
        remain = n % 10;
        n /= 10;
        reverse = reverse * 10 + remain;
    }
    return reverse;
}

int is_symmetric_mean() {
    for (int i = 0; i <= 256; i++) {
        int ans = pow(i, 2);
        if (ans == reverseNum(ans)) {
            cout << i << endl;
        }
    }
}

void howManyDay() {
    int year, mon, day;
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,};
    int totalDays[13] = {0};
    for (int i = 2; i < 13; i++) {
        totalDays[i] = totalDays[i - 1] + days[i - 1];
    }
    while (cin >> year >> mon >> day) {
        bool isleap = year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
        if (isleap && mon >= 3) {
            cout << totalDays[mon] + day + 1 << endl;
        } else {
            cout << totalDays[mon] + day << endl;
        }
    }
}

void printRectangle() {
    int n;
    cin >> n;
    int edge = (n - 1) * 2 + n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < edge - n - i * 2; j++) {
            cout << " ";
        }
        for (int j = 0; j < n + i * 2; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void nextDay() {
    int year, mon, day, n;
    int mons[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (scanf("%d%d ", &year, &n) != EOF) {
        mon = 1;
        day = 1;
        for (int i = 0; i < n - 1; i++) {
            bool isLeap = year % 400 == 0 || year % 100 != 0 && year % 4 == 0;
            if (isLeap) {
                mons[2] = 29;
            } else {
                mons[2] = 28;
            }
            day++;
            if (day > mons[mon]) {
                mon++;
                day = 1;
                if (mon > 12) {
                    year++;
                    mon = 1;
                }
            }
        }
        printf("%04d-%02d-%02d\n", year, mon, day);
    }
}

void leave_tree() {
    int l, m;
    int tree[100050] = {0};
    scanf("%d %d", &l, &m);
    for (int i = 0; i <= l; i++) {
        tree[i] = 1;
    }
    for (int s = 0; s < m; s++) {
        int left, right;
        scanf("%d %d", &left, &right);
        for (int i = left; i <= right; i++) {
            tree[i] = 0;
        }
    }
    int count = 0;
    for (int i = 0; i <= l; i++) {
        count += tree[i];
    }
    printf("%d", count);
}

void phone_key() {
    map<string, int> inputTime = {
            {"a", 1},
            {"b", 2},
            {"c", 3},
            {"d", 1},
            {"e", 2},
            {"f", 3},
            {"g", 1},
            {"h", 2},
            {"i", 3},
            {"j", 1},
            {"k", 2},
            {"l", 3},
            {"m", 1},
            {"n", 2},
            {"o", 3},
            {"p", 1},
            {"q", 2},
            {"r", 3},
            {"s", 4},
            {"t", 1},
            {"u", 2},
            {"v", 3},
            {"w", 1},
            {"x", 2},
            {"y", 3},
            {"z", 4}
    };
    map<string, int> keyMap = {
            {"a", 2},
            {"b", 2},
            {"c", 2},
            {"d", 3},
            {"e", 3},
            {"f", 3},
            {"g", 4},
            {"h", 4},
            {"i", 4},
            {"j", 5},
            {"k", 5},
            {"l", 5},
            {"m", 6},
            {"n", 6},
            {"o", 6},
            {"p", 7},
            {"q", 7},
            {"r", 7},
            {"s", 7},
            {"t", 8},
            {"u", 8},
            {"v", 8},
            {"w", 9},
            {"x", 9},
            {"y", 9},
            {"z", 9}
    };
    char str[150];
    scanf("%s", str);
    string w = str;
    int totalTime = 0;
    int prenum = 1;
    for (int i = 0; i < w.length(); i++) {
        string curKey = string(1, w[i]);
        if (keyMap[curKey] == prenum) {
            totalTime = totalTime + 2 + inputTime[curKey];
        } else {
            totalTime += inputTime[curKey];
        }
    }
}

bool comp(int left, int right) {
    //先写不发生交换的所有情况
    if (left > right)return true;
    else return false;
}

void sort_test() {
    vector<int> a(150, 0);
    for (int i = 0; i < 100; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), comp);
}

void yuesefuQueastion() {
    int n, p, m;//循环数组用队列来实现
    while (1) {
        scanf("%d%d%d", &n, &p, &m);
        if (n == 0 && p == 0 && m == 0)return;
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
        for (int i = 0; i < p - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        while (!q.empty()) {
            for (int j = 0; j < m - 1; j++) {
                q.push(q.front());
                q.pop();
            }
            int num = q.front();
            q.pop();
            if (q.empty())cout << num << endl;
            else cout << num << ",";
        }
    }
}

void adoptAnimal() {
    int n, m, t;
    cin >> n;
    struct ani {
        int num;
        int order;

        ani(int a = 0, int b = 0) : num(a), order(b) {}
    };
    queue<ani> dogs, cats;
    vector<int> ans;
    int o = 1;
    for (int i = 0; i < n; i++) {
        cin >> m >> t;
        if (m == 1) {
            if (t > 0) {
                dogs.push(ani(t, o++));
            } else if (t < 0) {
                cats.push(ani(t, o++));
            } else continue;
        } else if (m == 2) {
            if (t == 0) {
                if (dogs.front().order > cats.front().order) {
                    ans.push_back(cats.front().num);
                    cats.pop();
                } else {
                    ans.push_back(dogs.front().num);
                    dogs.pop();
                }
            } else if (t == 1) {
                ans.push_back(dogs.front().num);
                dogs.pop();
            } else if (t == -1) {
                ans.push_back(cats.front().num);
                cats.pop();
            } else continue;
        }
    }
    for (auto i: ans) {
        cout << i << " ";
    }
    cout << endl;
}

void oulashai() {
    bool a[100001] = {1, 1};//记录是否是合数
    vector<int> b(1000001, 0);//存储素数
    long long n;
    int cnt = 0;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) b[++cnt] = i;
        for (int j = 1; j <= cnt; j++) {
            if (i * b[j] > n)break;//超出范围就退出
            a[i * b[j]] = 1;//素数的倍数不是素数
            if (i % b[j] == 0)break;//超级关键的只标记一次，筛除的是最小素因子
        }
    }
    for (int i = 1; i <= cnt; i++) {
        printf("%lld ", b[i]);
    }
}

void transposition() {
    char str[100000];
    while (fgets(str, sizeof(str), stdin) != nullptr) {
        string s = str;
        string ans(s.size(), ' ');
        s.pop_back();
        stack<int> st;
        vector<int> right_error;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')st.push(i);
            else if (s[i] == ')' && st.empty())right_error.push_back(i);
            else if (s[i] == ')' && !st.empty())st.pop();
            else continue;
        }
        for (auto i: right_error) {
            ans[i] = '?';
        }
        while (!st.empty()) {
            ans[st.top()] = '$';
            st.pop();
        }
        printf("%s\n%s\n", s.c_str(), ans.c_str());
    }
}

void file_operator(string position, int type, string content = "") {
    char buf[10000];
    fstream file;
    if (type == 1) {
        file.open(position, ios::in);//从文件中读取数据
        file >> buf;
        cout << buf << endl;
    } else if (type == 2) {
        file.open(position, ios::out);//写入数据到文件中去,从头开始写，直接覆盖
        file << content;
    } else if (type == 3) {
        file.open(position, ios::app);//追加到文件的末尾
        file << content;
    }
    file.close();
}

void pre_travel(TreeNode *root) {
    if (root == nullptr)return;
    cout << root->num;
    pre_travel(root->left);
    pre_travel(root->right);
}

void in_travel(TreeNode *root) {
    if (root == nullptr)return;
    in_travel(root->left);
    cout << root->num;
    in_travel(root->right);
}

void post_travel(TreeNode *root) {
    if (root == nullptr)return;
    post_travel(root->left);
    post_travel(root->right);
    cout << root->num;

}

TreeNode *pre_in_creat_tree(string pre, string in) {
    if (pre.size() == 0)return nullptr;
    else {
        char rootdate = pre[0];
        TreeNode *pNewNode = new TreeNode;
        pNewNode->num = rootdate;
        int pos = in.find(rootdate);
        string pleft = pre.substr(1, pos);//切割出左子串
        string pright = pre.substr(pos + 1);//切割出右子串
        string inleft = in.substr(0, pos);//切割出左子串
        string inright = in.substr(pos + 1);//切割出右子串
        pNewNode->left = pre_in_creat_tree(pleft, inleft);
        pNewNode->right = pre_in_creat_tree(pright, inright);
        return pNewNode;
    }
}

TreeNode *pre_blank_build_tree(int &i, string str) {
    if (str.size() == 0)return nullptr;
    char c = str[i++];
    if (c == '#')return nullptr;
    else {
        TreeNode *newNode = new TreeNode;
        newNode->num = c;
        newNode->left = pre_blank_build_tree(i, str);
        newNode->right = pre_blank_build_tree(i, str);
        return newNode;
    }
}

void hafftree() {
    int n;
    cin >> n;
    int a;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        cin >> a;
        pq.push(-a);
    }
    int res = 0;
    while (pq.size() > 1) {
        int left = pq.top();
        pq.pop();
        int right = pq.top();
        pq.pop();
        res = res + left + right;
        pq.push(left + right);
    }
    cout << -res << endl;
}

int main() {
//    char a[1000];
//    char b[1000];
//    while (scanf("%s%s", a, b) != EOF) {
//        string aa = a;
//        string bb = b;
//        post_travel(pre_in_creat_tree(aa, bb));
//    }
//    string a;
//    cin >> a;
//    int i = 0;
//    TreeNode *root = pre_blank_build_tree(i, a);
//    in_travel(root);
    return 0;
}
//ABC
//BAC
//FDXEAG
//XDEFAG
//ab##cd#gf###e##
//abc##de#g##f###
//5
//1 2 2 5 9