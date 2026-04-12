N = int(input()) 
S = input() 
K = int(input()) 

tmp = S[K-1]
st = ""
for t in S:
    if t != tmp:
        st = st + "*"
    else:
        st = st + t

print(st)