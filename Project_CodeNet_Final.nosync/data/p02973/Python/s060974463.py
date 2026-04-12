from bisect import bisect_right
N = int(input())
A = [int(input()) for _ in range(N)]

# 頭にappendは遅いため、逆にする
arr = []
l = 0
for a in A:
  a = -a
  idx = bisect_right(arr, a)
  if idx == l:
    arr.append(a)
    l += 1
  else:
    arr[idx] = a

print(l)