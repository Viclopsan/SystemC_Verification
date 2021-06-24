#include "driver.h"
#include "monitor.h"
#include "full_adder.h"

int sc_main(int argc, char* argv[]) {
	sc_core::sc_report_handler::set_actions("/IEEE_Std_1666/deprecated",sc_core::SC_DO_NOTHING);
	sc_signal<bool>t_a, t_b, t_cin, t_sum, t_cout;
	full_adder f1("FullAdderWithHalfAdder");
	f1 << t_a << t_b << t_cin << t_sum << t_cout;

	driver d1("GenerateWaveForms");
	d1.d_a(t_a);
	d1.d_b(t_b);
	d1.d_cin(t_cin);
	
	monitor mo1("MonitorWaveforms");
	mo1 << t_a << t_b << t_cin << t_sum << t_cout;

	sc_start(100, SC_NS);

	return(0);
}