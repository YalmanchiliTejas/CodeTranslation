n = int(input())
S = [input() for _ in range(n)]
a = "abcdefghijklmnopqrstuvwxyz"

for i in range(len(a)):
    tmp = 50
    for j in range(n):
          tmp = min(tmp,S[j].count(a[i]))
    print(a[i]*tmp,end="")
print("")