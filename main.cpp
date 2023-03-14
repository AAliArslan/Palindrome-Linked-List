/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		int count = 0;
		int middle = 0;
		int newCount = 0;
		int i;
		int temp;
		std::vector<int> PalindromeVector;
		ListNode* firstPointer = head;
		ListNode* secondPointer = head;
		while (head != nullptr) {
			count++;
			head = head->next;
		}
		std::cout << "count:" << count << std::endl;
		//if our linked list have odd number of nodes than we need to start from not the middle but next.
		if (count % 2) middle = 1 + count / 2;
		else middle = count / 2;
		newCount = middle;
		std::cout << "middle:" << middle << std::endl;
		while (newCount != 0) {
			PalindromeVector.push_back(secondPointer->val);
			secondPointer = secondPointer->next;
			newCount--;
		}
		if (count % 2) PalindromeVector.pop_back();
		for (int j = 0; j < PalindromeVector.size(); j++) {
			std::cout << PalindromeVector[j] << std::endl;
		}

		count = 0;
		i = PalindromeVector.size() - 1;
		while (count <= middle && i >= 0) {
			std::cout << "Second Pointer:" << secondPointer->val << "    " << "PalindromeVector[i]:" << PalindromeVector[i] << std::endl;
			if (secondPointer->val != PalindromeVector[i]) return false;
			secondPointer = secondPointer->next;
			count++;
			i--;
		}
		return true;
	}
};