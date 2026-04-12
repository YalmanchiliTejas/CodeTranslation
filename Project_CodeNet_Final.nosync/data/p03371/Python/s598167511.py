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
    [A, B, C, X, Y] = [int(input_raw[0]), int(input_raw[1]), int(input_raw[2]), int(input_raw[3]), int(input_raw[4])]

    min_cost = sys.maxint
    for c in range(max(X, Y) * 2 + 1):
        a = max(int((X - 0.5 * c) + 0.5), 0)
        b = max(int((Y - 0.5 * c) + 0.5), 0)
        cost = a * A + b * B + c * C
        if cost < min_cost:
            min_cost = cost
    print min_cost

if __name__ == '__main__':
    main()