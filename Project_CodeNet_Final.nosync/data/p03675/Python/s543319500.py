n = int(raw_input())
A = map(int, raw_input().split())

e = A[::2]
o = A[1::2]
ans = e[::-1] + o
if n % 2 == 0:
    ans = ans[::-1]
print " ".join(map(str, ans))
