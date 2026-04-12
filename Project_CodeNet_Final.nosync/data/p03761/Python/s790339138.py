import collections
n=int(input())
c=[0]*n
alphabet=set()
for i in range(n):
    s=input()
    counter=collections.Counter(s)
    c[i]=counter
    for moji in s:
        if(moji not in alphabet):
            alphabet.add(moji)
alphabet=sorted(alphabet)
text=''
for moji in alphabet:
    count=10000
    for i in range(n):
        if(count>c[i][moji]):
            count=c[i][moji]
    text+=moji*count
print(text)

