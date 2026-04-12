#n, m, q = map(int, input().split())
#List = list(map(int, input().split()))
#req = [list(map(int, input().split())) for _ in range(q)]
#t = t[:-1]
#print(ans[j], end = "") 改行無しで出力
#[0]*n
#sort = sorted(a)[::-1] 降順
#if l[i] == l[j]: continue
n = int(input())
a = list(map(int, input().split()))
ans = 0
min = 0
new_list = list(reversed(a))

for i in range(len(new_list) - 1):
    min += new_list[i]
    ans +=  min * new_list[i+1]


print(ans % 1000000007)
