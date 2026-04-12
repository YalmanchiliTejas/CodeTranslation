n = int(input())
a = [int(each) for each in input().split()]

result = 0
s = sum(a)
for i in range(len(a)):
    s = (s-a[i])
    result += s % 1000000007 * a[i]
print(result % 1000000007)