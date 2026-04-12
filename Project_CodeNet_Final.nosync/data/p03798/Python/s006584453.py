# SS, SW, WS, WWのときについてそれぞれ調べればよい

N=int(input())
s=input()
A=["SS","SW","WS","WW"]
for i,c in enumerate(s):
    for j in range(4):
        if A[j][-2:]=="SS":
            if c=="o":A[j]+="S"
            else:A[j]+="W"
        elif A[j][-2:]=="SW":
            if c=="o":A[j]+="W"
            else:A[j]+="S"
        elif A[j][-2:]=="WS":
            if c=="o":A[j]+="W"
            else:A[j]+="S"
        else:
            if c=="o":A[j]+="S"
            else:A[j]+="W"
A=[t[1:-1]for t in A if t[:2]==t[-2:]]
print(A[0]if A else-1)