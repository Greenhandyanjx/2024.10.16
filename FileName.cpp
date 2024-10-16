#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == NULL)return NULL;
        ListNode* slow = head, * fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head, * newHead = NULL;
        while (cur) {
            ListNode* temp = cur->next;
            cur->next = newHead;
            newHead = cur;
            cur = temp;
        }
        return newHead;
    }
    void reorderList(ListNode* head) {
        ListNode* cur = head;
        ListNode* mid = middleNode(head);
        ListNode* head1 = reverseList(mid);
        while (head1 && head1->next) {
            ListNode* dhead = cur->next;
            ListNode* dhead1 = head1->next;
            head1->next = cur->next;
            cur->next = head1;
            cur = dhead;
            head1 = dhead1;
        }
    }
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == NULL)return NULL;
        ListNode* slow = head, * fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL)return NULL;
        ListNode* slow = head, * fast = head;
        int n = 0;
        while (true) {
            if (fast->next == NULL || fast->next->next == NULL)return NULL;
            fast = fast->next->next;
            slow = slow->next;
            n++;
            if (fast == slow) {
                while (slow != head) {
                    slow = slow->next;
                    head = head->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1, * dummyhead1=head1, * head2, * dummyhead2=head2;
        ListNode* cur = head;
        while (cur) {
            if (cur->val < x) {
                head1->next = cur;
                head1 = cur;
            }
            else {
                head2->next = cur;
                head2 = cur;
            }
        }
        head1->next = dummyhead2->next;
        head2->next = NULL;
        return dummyhead1->next;
    }
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummyhead;
        dummyhead->next = head;
        ListNode* cur = dummyhead;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                while (cur->next->val == cur->next->next->val) {
                    cur->next = cur->next->next;
                }
            }
            else
                cur = cur->next;
        }
        return dummyhead->next;
    }
};
class Solution {
public:
    int work(vector<int>& nums, int k) {
        int len = 0;
        for (auto num : nums) {
            if (len < k || nums[len - k] != num)
                nums[len++] = num;
        }
        return len;
    }
    int removeDuplicates(vector<int>& nums) {
        return work(nums, 2);
    }
};