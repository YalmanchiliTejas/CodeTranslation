import sys


def CheckRangeInt(input_str,_min,_max):

    if input_str.isdecimal()==0 or int(input_str)<_min or int(input_str)>_max:
        print("error")
        sys.exit()

    return int(input_str)


def CheckRangeList(input_list,_min,_max):
    for i in range(len(input_list)) :
        if H[i]<_min or H[i]>_max :
            print("error")
            sys.exit()
    return input_list

N=input()

# if N.isdecimal()==0 or int(N)<1 or int(N)>20:                                                                                                                                                             
#     print("error")                                                                                                                                                                                        
#     sys.exit()                                                                                                                                                                                            

# N=int(N)                                                                                                                                                                                                  
N=CheckRangeInt(N,1,20)


H=list(map(int,input().strip().split()))

if len(H)!=N :
    print("error")
    sys.exit()

# for i in range(N) :                                                                                                                                                                                       
#     if H[i]<1 or H[i]>100 :                                                                                                                                                                               
#         print("error")                                                                                                                                                                                    
#         sys.exit()                                                                                                                                                                                        

H=CheckRangeList(H,1,100)

highest=0
can_see=0

for i in range(N):
    if H[i]>=highest :
        can_see=can_see+1
        highest=H[i]

print(can_see)


