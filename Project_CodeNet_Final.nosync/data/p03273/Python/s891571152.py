h,w=map(int,input().split())
a=[[j for j in input()] for i in range(h)]
b=[x for x in a if "#" in x]  #1つでも#があれば、bにいれる　つまり全部...ならば除外される
c=zip(*[y for y in zip(*b) if "#" in y]) #zip(*)で転置行列になる！！！
for d in c:print("".join(d))