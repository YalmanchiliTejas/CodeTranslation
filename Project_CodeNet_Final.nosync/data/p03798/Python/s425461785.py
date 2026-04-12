input();s=input();A=["SS","SW","WS","WW"]
for c in s:A=[t+"SW"[(t[-1]==t[-2])-(c=="o")]for t in A]
A=[t[1:-1]for t in A if t[:2]==t[-2:]];print(A[0]if A else-1)