N = int(input())
S = [sorted(list(input())) for _ in range(N)]

res = ""
strdict = {}
for c in ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]:
    tmp = [0] * N
    for i, s in enumerate(S):
        tmp[i] = s.count(c)
    for t in range(min(tmp)):
        res += c
print(res)