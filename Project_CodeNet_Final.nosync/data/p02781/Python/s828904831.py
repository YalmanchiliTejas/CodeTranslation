N = int(input())
K = int(input())

l = len(str(N))
"""
print("N=",N)
print("K=",K)
print("l=",l,"桁")
"""
#l桁の数字

if K == 1:
    y = 9*(l-1)
    for i in range(1,10):
        p = i*10**(l-1)
        # print(p)
        if p <= N:
            y += 1
        else:
            break
    print(y)
    
elif K == 2:
    # print("mode 2")
    #l-1桁まででNより小さい数の個数
    y = 81*(l-1)*(l-2)//2
    # print(y)
    
    #l桁の数
    for i in range(1,int(str(N)[0])+1):
        for j in range(1,10):
            for k in range(l-1):
                # print(i,j,k)
                p = int(str(i)+"0"*k+str(j)+"0"*(l-2-k))
                if p <= N:
                    y += 1
                # print(p)
    print(y)

else:
    # print("mode 3")
    #l-1桁まででNより小さい数の個数
    y = 729*(l-1)*(l-2)*(l-3)//6
    # print(y)
    
    #l桁の数で頭の数がNのそれより小さい場合
    top = int(str(N)[0])
    y += (top-1)*81*(l-1)*(l-2)//2
    
    #l桁の数(頭の数字はNと一緒)
    for j in range(1,10):
        for k in range(1,10):
            for m in range(l-2):
                for n in range(l-2-m):
                    # print(m,n,l-3-m-n)
                    p = int(str(top)+"0"*m+str(j)+"0"*n+str(k)+"0"*(l-3-m-n))
                    if p <= N:
                        y += 1
                    # print("p:",p)
    print(y)