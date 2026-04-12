n=int(input())
ini=5000
dic={
    "a":ini,
    "b":ini,
    "c":ini,
    "d":ini,
    "e":ini,
    "f":ini,
    "g":ini,
    "h":ini,
    "i":ini,
    "j":ini,
    "k":ini,
    "l":ini,
    "m":ini,
    "n":ini,
    "o":ini,
    "p":ini,
    "q":ini,
    "r":ini,
    "s":ini,
    "t":ini,
    "u":ini,
    "v":ini,
    "w":ini,
    "x":ini,
    "y":ini,
    "z":ini,
}

for _ in range(n):
    s=input()
    for i,v in dic.items():
        dic[i]=min(s.count(i), v)
ans=""
for i,v in sorted(dic.items()):
    ans+=i*v
print(ans)
