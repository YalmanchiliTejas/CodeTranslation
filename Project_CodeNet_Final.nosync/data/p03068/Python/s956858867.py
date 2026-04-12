N = int(input())
S = input()
K = int(input())

er = S[K-1]
Ss = [i if i == er else "*" for i in S]
a = ""
for i in Ss:
    a += i
print(a)