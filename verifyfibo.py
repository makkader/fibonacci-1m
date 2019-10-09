# Used this script to verify the correctness of fibo.c
import sys
import math
import subprocess
import random

curFiboIdx = 2
A = 0
B = 1


def getFibo(N):
    if (N == 0):
        return 0
    if (N == 1):
        return 0
    if (N == 2):
        return 1
    global curFiboIdx, A, B
    while(curFiboIdx < N):
        C = A+B
        A = B
        B = C
        curFiboIdx += 1
        # print B;
    return B


# main

# getFibo(20);
# sys.exit();
# nthFiboList=[2,500000,707106,866025,1000000,1118033,1224744,1322875,1414213,1500000,1581138,1658312,1732050,1802775,1870828,1936491,2000000,2061552,2121320,2179449,2236067,2291287,2345207,2397915,2449489,2500000,2549509,2598076,2645751,2692582,2738612,2783882,2828427,2872281,2915475,2958039,3000000,3041381,3082207,3122498,3162277,3201562,3240370,3278719,3316624,3354101,3391164,3427827,3464101,3500000,3535533,3570714,3605551,3640054,3674234,3708099,3741657,3774917,3807886,3840572,3872983,3905124,3937003,3968626,4000000,4031128,4062019,4092676,4123105,4153311,4183300,4213074,4242640,4272001,4301162,4330127,4358898,4387482,4415880,4444097,4472135,4500000,4527692,4555216,4582575,4609772,4636809,4663689,4690415,4716990,4743416,4769696,4795831]
nthFiboList = sorted(random.sample(range(100000), 5))
print(nthFiboList)

# for i in xrange(200,500000):
for k in nthFiboList:
    i = k-1
    p = subprocess.Popen(['./fibo.out '+str(i)], shell=True, stdout=subprocess.PIPE)
    out, err = p.communicate()

    p = subprocess.Popen(['cat nthFibonacci'], shell=True, stdout=subprocess.PIPE)
    out, err = p.communicate()

    fiboFromC = out.strip()
    fiboFromPython = str(getFibo(i))
    if fiboFromPython == fiboFromC:
        print(i, " OK")
    else:
        print(i, " Wrong")
        print("c:py ", fiboFromC, ":", fiboFromPython)
        break

print("Done!")
