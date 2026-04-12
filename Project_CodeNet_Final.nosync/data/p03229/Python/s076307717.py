import sys
from collections import deque
import copy
import math
def get_read_func(fileobject):
    if fileobject == None :
        return raw_input
    else:
        return fileobject.readline

def main():
    if len(sys.argv) > 1:
        f = open(sys.argv[1])
    else:
        f = None
    read_func = get_read_func(f);
    input_raw = read_func().strip().split()
    [N] = [long(input_raw[0])]
    A = []
    for i in range(N):
        input_raw = read_func().strip().split()
        A.append(long(input_raw[0]))

    A.sort()

    B = deque([])
    is_back = False
    is_append_left = True
    is_append_left_back = False

    for i in range(N):
##        if len(B) == 0:
##            B.append(A[i])
##        else:
            if is_back == False:
                x = A[i/2]
                if is_append_left == True:
                    B.appendleft(x)
                    is_append_left = False
                else:
                    B.append(x)
                    is_append_left = True

            else:
                x = A[len(A) - 1 - i/2]
                if is_append_left_back == True:
                    B.appendleft(x)
                    is_append_left_back = False
                else:
                    B.append(x)
                    is_append_left_back = True

##            if abs(B[0] - x) > abs(B[len(B) - 1] - x):
##                B.appendleft(x)
##            elif abs(B[0] - x) < abs(B[len(B) - 1] - x):
##                B.append(x)
##            else:
##                if is_back == False:
##                    if B[0] <= B[len(B) - 1]:
##                        B.append(x)
##                    else:
##                        B.appendleft(x)
##                else:
##                    if B[0] >= B[len(B) - 1]:
##                        B.append(x)
##                    else:
##                        B.appendleft(x)
            if is_back == False:
                is_back = True
            else:
                is_back = False
    score1 = 0L
    for i in range(N -1):
        score1 += abs(B[i] - B[i + 1])


    A.sort(reverse = True)

    B = deque([])
    is_back = False
    is_append_left = True
    is_append_left_back = False
    for i in range(N):
##        if len(B) == 0:
##            B.append(A[i])
##        else:
            if is_back == False:
                x = A[i/2]
                if is_append_left == True:
                    B.appendleft(x)
                    is_append_left = False
                else:
                    B.append(x)
                    is_append_left = True

            else:
                x = A[len(A) - 1 - i/2]
                if is_append_left_back == True:
                    B.appendleft(x)
                    is_append_left_back = False
                else:
                    B.append(x)
                    is_append_left_back = True

##            if abs(B[0] - x) > abs(B[len(B) - 1] - x):
##                B.appendleft(x)
##            elif abs(B[0] - x) < abs(B[len(B) - 1] - x):
##                B.append(x)
##            else:
##                if is_back == True:
##                    if B[0] < B[len(B) - 1]:
##                        B.append(x)
##                    else:
##                        B.appendleft(x)
##                else:
##                    if B[0] > B[len(B) - 1]:
##                        B.append(x)
##                    else:
##                        B.appendleft(x)
            if is_back == False:
                is_back = True
            else:
                is_back = False
    score2 = 0L
    for i in range(N -1):
        score2 += abs(B[i] - B[i + 1])

    print max(score1, score2)


if __name__ == '__main__':
    main()
