import collections
res=[]
alphabet=list("abcdefghijklmnopqrstuvwxyz")
n=int(input())
S=[collections.Counter(list(input())) for i in range(n)]
for c in alphabet:
    res.append(min(dic[c] for dic in S))
print("".join(alphabet[i]*res[i] for i in range(26)))