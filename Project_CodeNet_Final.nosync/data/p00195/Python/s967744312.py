import sys
while True:
    sells=[]
    for i in range(5):
        s1,s2=[int(j) for j in input().split(" ")]
        if s1==0 and s2==0:
            sys.exit()
        sells.append(s1+s2)
    print(chr(ord('A')+sells.index(max(sells))),max(sells))

