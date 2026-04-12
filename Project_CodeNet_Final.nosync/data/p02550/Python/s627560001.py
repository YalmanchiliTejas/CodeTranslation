import sys

n,x,m = (int(i) for i in input().split())
l = [x]
ans = x
memo_array = [-1]*(m+1)

for i in range(1,n):
    ans = ans**2%m
    idx = memo_array[ans]
    if idx != -1:
        loop_num, mod = divmod((n-idx),(i-idx))
        print(sum(l[:idx]) + sum(l[idx:])*(loop_num)+sum(l[idx:idx+mod]))
        sys.exit()
    l.append(ans)
    memo_array[ans]=i
print(sum(l))