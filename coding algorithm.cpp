#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int value) : next(nullptr), val(value) {}
};

//day1
int binary_search(vector<int> &a, const int &t) {
    int left = 0;
    int right = a.size();
    while (left < right) {
        int middle = left + ((right - left) >> 1);
        if (a[middle] > t)right = middle;
        else if (a[middle] < t)left = middle + 1;
        else return middle;
    }
    return -1;
}

int remove_ele(vector<int> &a, const int &t) {
    int slowIndex = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != t) {
            a[slowIndex++] = a[i];
        }
    }
    return slowIndex;
}

vector<int> pow_sort(vector<int> &a) {
    int k = a.size() - 1;
    vector<int> ans(a.size(), 0);
    for (int i = 0, j = a.size() - 1; i <= j;) {
        if (a[i] * a[i] < a[j] * a[j]) {
            ans[k--] = a[j] * a[j];
            j--;
        } else {
            ans[k--] = a[i] * a[i];
            i++;
        }
    }
    return ans;
}

int slid_window(int s, vector<int> &num) {
    int result = INT_MAX;
    int sum = 0;
    int i = 0;
    int window = 0;
    for (int j = 0; j < num.size(); i++) {
        sum += num[j];
        while (sum >= s) {
            window = j - i + 1;
            result = min(result, window);
            sum -= num[i++];
        }
    }
    return result == INT_MAX ? 0 : result;
}

vector<vector<int>> spiral_matrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int startx = 0, starty = 0;//定义每次的起始和结束位置
    int loop = n / 2;
    int mid = n / 2;
    int count = 1;
    int offset = 1;//控制每一条边遍历的长度
    int i, j;
    while (loop--) {
        i = startx;
        j = starty;
        //四个for模拟旋转一圈，按左闭右开来填充
        for (j = starty; j < n - offset; j++) {
            res[startx][j] = count++;
        }
        for (i = startx; i < n - offset; i++) {
            res[i][j] = count++;
        }
        for (; j > starty; j--) {
            res[i][j] = count++;
        }
        for (; i > startx; i--) {
            res[i][j] = count++;
        }
        offset++;
    }
    if (n % 2) {
        res[mid][mid] = count;
    }
    return res;
}

//day2
ListNode *remove_ele_list(ListNode *head, int val) {
    //删除头部节点
    while (head->val == val) {
        ListNode *tmp = head;
        head = head->next;
        delete tmp;
    }
    ListNode *cur = head;
    while (cur != nullptr && cur->next != nullptr) {
        if (cur->next->val == val) {
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        } else {
            cur = cur->next;
        }
    }
    return head;
}

ListNode *reverse_list(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *cur = head;
    ListNode *tmp = nullptr;
    while (cur != nullptr) {
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

ListNode *swap_pair_list(ListNode *head) {
    ListNode *virtual_head = new ListNode(0);
    virtual_head->next = head;
    ListNode *cur = virtual_head;
    while (cur->next != nullptr && cur->next->next != nullptr) {
        ListNode *tmp1 = cur->next;//记录第一个节点
        ListNode *tmp2 = cur->next->next;//记录第二个节点
        ListNode *tmp3 = cur->next->next->next;//记录第三个节点
        cur->next = tmp2;
        cur->next->next = tmp1;
        cur->next->next->next = tmp3;
        cur = tmp2;
    }
    return virtual_head->next;
}

ListNode *delete_Nele_list(ListNode *head, int n) {
    ListNode *virtualNode = new ListNode(0);
    ListNode *slowNode = head;
    ListNode *fastNode = head;
    while (n-- && fastNode != nullptr) {
        fastNode = fastNode->next;
    }
    fastNode = fastNode->next;
    while (fastNode != nullptr) {
        fastNode = fastNode->next;
        slowNode = slowNode->next;
    }
    ListNode *tmp = slowNode->next;
    slowNode->next = slowNode->next->next;
    delete tmp;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* curA =headA;
    ListNode* curB = headB;
    int lenA =0,lenB = 0;
    while(curA!= nullptr){
        lenA++;
        curA = curA->next;
    }
    while(curB!= nullptr){
        lenB++;
        curB = curB->next;
    }
    curA = headA;
    curB =headB;
    if(lenB>lenA){
        swap(lenA,lenB);
        swap(curA,curB);
    }
    int gap = lenA-lenB;
    while(gap--){
        curA =curA->next;
    }
    while(curA!= nullptr){
        if(curA == curB){
            return curA;
        }
        curA = curA->next;
        curB = curB->next;
    }
    return nullptr;
}