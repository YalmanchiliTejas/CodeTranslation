N = int(input())
a = list(map(int, input().split()))

ans = []
for i in range(N - 1, -1, -2):
    ans.append(a[i])
    
tmp_ans = []
for i in range(N - 2, -1, -2):
    tmp_ans.append(a[i])
tmp_ans.reverse()
ans += tmp_ans 
print(" ".join(map(str, ans)))