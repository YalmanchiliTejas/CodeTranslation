from functools import lru_cache
n=int(input())
k=int(input())
@lru_cache(None)
def F(x,y):  #xという数字に対して0出ない数字がyこのモノの個数
    if x<10:
        if y==1:
            return x
        elif y==0:
            return 1
        else:
            return 0
    else:
        res=0
        q,r=divmod(x,10)
        res+=F(q,y)  #最後の桁が0
        if y>=1:
            res+=r*F(q,y-1) #最後の桁が1-r
            res+=(9-r)*F(q-1,y-1) #最後がr+1,,,9
        return res
print(F(n,k))