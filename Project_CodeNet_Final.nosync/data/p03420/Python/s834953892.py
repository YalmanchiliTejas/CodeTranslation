import sys
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
    [N, K] = [int(input_raw[0]), int(input_raw[1])]
    S = 0
    for b in range(K + 1, N + 1):
        i_max = (N - K)/b
        t = max((i_max * b + (b - 1)) - N, 0)
        S += (((N - K)/b) + 1) * (b-K) - t
    if K == 0:
        S -= N
    print S

if __name__ == '__main__':
    main()