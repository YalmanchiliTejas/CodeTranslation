N = int(input())
n_list = list(map(int,input().split()))

ans = 1
max_n = n_list[0]

for i in n_list[1:]:
 if i >= max_n:
  max_n = i
  ans += 1

print(ans)