while True:
  try:
      A=[]
      for i in range(5):
        s1,s2=map(int,input().split())
        if s1==0 and s2==0:
          break
        s=s1+s2
        A.append(s)
      if s==0:
        break
      for i in range(len(A)):
        if A[i]==max(A):
          if i==0:
            print("A",A[i])
          if i==1:
            print("B",A[i])
          if i==2:
            print("C",A[i])
          if i==3:
            print("D",A[i])
          if i==4:
            print("E",A[i])
  except EOFError:
      break
  
