N = int(input())
S = str(input())
K = int(input())
c = S[K-1]
re = ""
for i in S:
    if i != c:
        re+="*"
    else:
        re+=i
print(str(re))