h, w = map(int, input().split())
a = [input() for _ in range(h)]
#print(a)
a = [ai for ai in a if set(ai) != {'.'}] #.がないときにはリストに入れる tf .のみを剥がす
#print(a)
a = ["".join([a[i][j] for i in range(len(a))]) for j in range(len(a[0]))] #iとjの反転
#print(a)
#for ai in a:
#    print(ai)
a = [ai for ai in a if set(ai) != {'.'}]
#print(a)
a = ["".join([a[i][j] for i in range(len(a))]) for j in range(len(a[0]))]
#print(a)
for ai in a:
    print(ai)
