n=int(input())
s=input()
k=int(input())
l=list(s)
l_a=['*' if not l[k-1] in s else l[k-1] for s in l]
l_aa="".join(l_a)
print(l_aa)