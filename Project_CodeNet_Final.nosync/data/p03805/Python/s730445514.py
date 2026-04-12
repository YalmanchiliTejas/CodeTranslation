n,m=map(int,input().split())
a=[]

for i in range(m):
    ai,bi=map(int,input().split())
    a.append([ai,bi])
              
ni=[0]*n
nii=[]
    
def pathm(n,a,bi,pcnt,ni):
    if n==1:
        pcnt=pcnt+1
#        print("2:","n:",n,"bi:",bi,"pcnt:",pcnt)
        return pcnt
    else:
        n=n-1
        nii.append(bi)
        for mm in range(m):
            if a[mm][0]==bi and not a[mm][1] in nii:
#            if a[mm][0]==bi :
                ni[a[mm][1]-1]=1
#                print("1:","n:",n,"mm:",mm,"a[mm][1]:",a[mm][1],"pcnt:",pcnt)
                pcnt=pathm(n,a,a[mm][1],pcnt,ni)
            if a[mm][1]==bi and not a[mm][0] in nii:
#            if a[mm][1]==bi  and ni[a[mm][0]-1]==0 :
                ni[a[mm][0]-1]=1
#                ni[mm]=1
#                print("1:","n:",n,"mm:",mm,"a[mm][0]:",a[mm][0],"pcnt:",pcnt)
                pcnt=pathm(n,a,a[mm][0],pcnt,ni)
        nii.pop()
        return pcnt       
                
pcnt=0
pcnt1=pathm(n,a,1,pcnt,ni)
print(pcnt1)
