N = int(input())
S = input()
K = int(input())

good_no = S[K-1]
ans = []
for i in range (N):
    if S[i] == good_no:
        ans.append(good_no)
    else:
        ans.append('*')
print(''.join(ans))