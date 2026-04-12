import sys
sys.setrecursionlimit(6000)

n_node, n_path = [int(x) for x in input().split()]

A = [[0]*2 for x in range(n_path)]

for i in range(n_path):
	A[i][0], A[i][1] = [int(x) for x in input().split()]



def serch(A, cur_node, old, n_node):
	
	ans = 0
		
	if len(old) == (n_node-1):
		return 1
	
	for i in range(len(A)):
		
		if cur_node == A[i][0] and not(A[i][1] in old):
			A_copy = A.copy()
			A_copy.pop(i)
			old_copy = old.copy()
			old_copy.append(cur_node)
			ans += serch(A_copy, A[i][1], old_copy, n_node)
		
		elif cur_node == A[i][1] and not(A[i][0] in old):
			A_copy = A.copy()
			A_copy.pop(i)
			old_copy = old.copy()
			old_copy.append(cur_node)
			ans += serch(A_copy, A[i][0], old_copy, n_node)
	return ans

print(serch(A, 1, [], n_node))

