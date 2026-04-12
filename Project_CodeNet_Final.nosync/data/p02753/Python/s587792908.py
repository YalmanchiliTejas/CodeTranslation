
class abc_158:
    
    def __init__(self):
        pass
    
    def A(self):
        S=input()
        if "BA" in S or "AB" in S:print("Yes")
        else:print("No")
    
    def B(self):
        NAB=list(map(int,input().split()))
        tail = NAB[0]%(NAB[1]+NAB[2]) if NAB[0]%(NAB[1]+NAB[2])<NAB[1] else NAB[1]
        ans=((NAB[0]/(NAB[1]+NAB[2]))*NAB[1])+tail
        print(int(ans))
            
    def C(self):
        AB=list(map(int,input().split()))
        ans=-1
        
        #A<B<100
        for i in range(1,101):
            if AB[0]==int(i*0.08) and AB[1]==int(i*0.1):
                ans=i
                break
            else:continue
        print(ans)
            
    def D(self):
        pass
        
    def E(self):
        pass
    
    def F(self):
        pass
    
    
if __name__=='__main__':
    obj=abc_158()
    obj.A()