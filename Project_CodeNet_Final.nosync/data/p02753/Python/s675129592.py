Flag =  0 
S = input()
SA = [str(c) for c in S]
#A = list(['A','A','A'])
#B = list(['B','B','B'])
S1 = SA[0]
S2 = SA[1]
S3 = SA[2]
if(S1 == S2 == S3):
    print("No")
else:
    print("Yes")