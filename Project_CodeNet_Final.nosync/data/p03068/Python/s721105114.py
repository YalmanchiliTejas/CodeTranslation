#https://atcoder.jp/contests/tenka1-2019-beginner/tasks/tenka1_2019_b

N = int(input())
S = str(input())
K = int(input())

Sarray = list(S)
a = Sarray[K - 1]
Sprc = ''

for i in range(len(Sarray)):
    if Sarray[i] != a:
        Sarray[i] = '*'
    Sprc += Sarray[i]

print(Sprc)