def A():
    S = input()
    for i in range(len(S)):
        if S[i:i+2] ==  "AC":
            return 1

    return 0

if __name__ == '__main__':
    result = A()
    if result == 1:
        print("Yes")
    else:
        print("No")
 
        
