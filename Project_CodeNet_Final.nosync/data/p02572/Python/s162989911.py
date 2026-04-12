n = int(input())
a = list(map(int, input().split()))
b = [x*x for x in a]

#print(a)
#print(b)

s = sum(a)
s = s * s - sum(b)
s = s // 2
s = s % 1000000007

print(s)

# (a+b+c)^2 = a^2 + b^2 + c^2 + 2ab + 2ac + 2bc