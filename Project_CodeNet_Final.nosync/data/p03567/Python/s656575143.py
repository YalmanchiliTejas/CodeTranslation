import sys

def func(S):
    for i in range(len(S)-1):
        if(S[i] == 'A' and S[i+1] == 'C'):
            print("Yes")
            sys.exit()
    print("No")
    sys.exit()

S = input()
func(S)
