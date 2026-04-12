#C
N = int(input())
S = [list(str(input())) for i in range(N)]

char = []
for i in range(N):
    if i == 0:
        Si = S[i]
        Si.sort()
        char = Si
    else:
        new = []
        Si = S[i]
        Si.sort()
        
        for c in char:
            if c in Si:
                new.append(c)
                Si.remove(c)
        char = new
    #print(char)
        
ans = ""
for c in char:
    ans+=c
print(ans)
