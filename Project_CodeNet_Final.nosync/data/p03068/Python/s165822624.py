N = int(input())
Str = input()
K = int(input())
List = list(Str)

chikan = List[K-1]

for i in range(N):
    if List[i] != chikan:
        List[i] = '*'

Str = "".join(List)
print(Str)
