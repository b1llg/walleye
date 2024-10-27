#include "WalleyeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
WalleyeApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

WalleyeApp::WalleyeApp(InputParameters parameters) : MooseApp(parameters)
{
  WalleyeApp::registerAll(_factory, _action_factory, _syntax);
}

WalleyeApp::~WalleyeApp() {}

void
WalleyeApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<WalleyeApp>(f, af, s);
  Registry::registerObjectsTo(f, {"WalleyeApp"});
  Registry::registerActionsTo(af, {"WalleyeApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
WalleyeApp::registerApps()
{
  registerApp(WalleyeApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
WalleyeApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  WalleyeApp::registerAll(f, af, s);
}
extern "C" void
WalleyeApp__registerApps()
{
  WalleyeApp::registerApps();
}
