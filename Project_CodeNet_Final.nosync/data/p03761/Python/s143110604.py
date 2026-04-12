n=int(input())
slist=[]
for i in range(n):
    slist.append(input())
alphabet=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
times=[]
for i in alphabet:
    saitei=1000
    for j in range(n):
        kosu=slist[j].count(i)
        if kosu<saitei:
            saitei=kosu
    times.append(saitei)
ans=[]
for i in range(len(alphabet)):
    for j in range(times[i]):
        ans.append(alphabet[i])
for i in range(len(ans)):
    print(ans[i],end="")
print("")
