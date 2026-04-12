from collections import Counter,defaultdict
import sys,heapq,bisect,math,itertools,string,queue,datetime
mod = 10**9+7
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_str(): return list(sys.stdin.readline().split())

n = int(input())
s = [0] * n
for i in range(n):
    s[i] = input()
cnt_st = Counter(s[0])
for i in range(1,n):
    memo = []
    cnt_tmp = Counter(s[i])
    for key in cnt_st.keys():
        if key in cnt_tmp.keys():
            cnt_st[key] = min(cnt_st[key], cnt_tmp[key])
        else:
            memo.append(key)
    for j in memo:
        cnt_st.pop(j)
# print(cnt_st)
ans = []
for key in cnt_st.keys():
    while cnt_st[key]:
        ans.append(key)
        cnt_st[key] -= 1
ans.sort()
print(''.join(ans))

