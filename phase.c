#include <stdio.h>
#include <math.h>

// 定义结构光单元
typedef struct {
    double E;        // 电磁场强度（标量模拟）
    double phase;    // 相位 φ （弧度）
    double polarization; // 偏振态 σ（简化为角度）
    int topologicalCharge; // 拓扑态 τ，如轨道角动量（OAM）
    double path[3];  // 空间路径向量 Ω[x, y, z]
} LightStructUnit;
LightStructUnit createLightUnit(double E, double phase, double polarization, int tau, double x, double y, double z) {
    LightStructUnit unit;
    unit.E = E;
    unit.phase = phase;
    unit.polarization = polarization;
    unit.topologicalCharge = tau;
    unit.path[0] = x;
    unit.path[1] = y;
    unit.path[2] = z;
    return unit;
}
void printLightUnit(LightStructUnit unit) {
    printf("结构光单元参数：\n");
    printf("  电磁场强度 E     = %.3f\n", unit.E);
    printf("  相位 φ            = %.3f rad\n", unit.phase);
    printf("  偏振态 σ          = %.3f deg\n", unit.polarization);
    printf("  拓扑阶 τ (OAM)    = %d\n", unit.topologicalCharge);
    printf("  空间路径 Ω        = [%.3f, %.3f, %.3f]\n",
           unit.path[0], unit.path[1], unit.path[2]);
}

int main() {
    // 创建一个结构光单元：E=1.0，phase=π/2，偏振45度，OAM=3，方向向量(1,0,0)
    LightStructUnit myLight = createLightUnit(1.0, M_PI/2, 45.0, 3, 1.0, 0.0, 0.0);

    // 打印参数
    printLightUnit(myLight);

    return 0;
}
