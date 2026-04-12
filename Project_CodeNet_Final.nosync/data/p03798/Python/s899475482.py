n=int(input())
a=input()
s="SW"
for d in range(2):
    for c in range(2):
        k=s[d]+s[c]
        for i in range(2,n+2):
            if k[i-1]=="S":
                if a[(i-1)%n]=="o":
                    k+=k[i-2]
                else:
                    k+=("W" if k[i-2]=="S" else "S")
            else:
                if a[(i-1)%n]=="o":
                    k+=("W" if k[i-2]=="S" else "S")
                else:
                    k+=k[i-2]
        else:
            if k[0]==k[-2] and k[1]==k[-1]:
                print(k[:-2])
                exit()
else:
    print(-1)