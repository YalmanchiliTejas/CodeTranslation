n = int(input())
s = input()
k = int(input())
c = s[k-1]
for i in range(n):
    print(c if c == s[i] else "*", end="")
print("")