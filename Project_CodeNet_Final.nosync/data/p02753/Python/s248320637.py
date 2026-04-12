import numpy as np
import math as m

def main(**kwargs):
    res = "Yes"

    if S == "AAA" or S == "BBB":
        res = "No"

    return res

if __name__ == "__main__":
    cin = np.array(input().split(" "))
    S, *_ = cin

    cout = main(S=S)
    print(cout)