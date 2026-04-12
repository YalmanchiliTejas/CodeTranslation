def LI(): return list(map(int, input().split()))
def LS(): return input().split()
def I(): return int(input())
def S(): return input()

n = I()
a = LI()
even = a[0::2]
odd = a[1::2]

if n % 2:
    ans = even[::-1]
    ans.extend(odd)
else:
    ans = odd[::-1]
    ans.extend(even)
for i in ans:
    print(i, end=" ")